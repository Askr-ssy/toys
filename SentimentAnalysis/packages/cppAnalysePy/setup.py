from setuptools import setup,Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

import os
from distutils.sysconfig import get_python_lib

ROOT_DIR = os.path.dirname(os.path.abspath(__file__))
SITE_PACKAGE_DIR = os.path.join(ROOT_DIR,"")


class get_pybind_include(object):

    def __init__(self,user=False):
        self.user=user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)



ext_modules = [
    Extension(
        "libanalyse",
        ["src/main.cpp"],
        include_dirs=[
            get_pybind_include(),
            get_pybind_include(user=True),
            "analyse/include"
        ],
        language="c++"
    )
]

def has_flag(compiler, flagname):
    """Return a boolean indicating whether a flag name is supported on
    the specified compiler.
    """
    import tempfile
    with tempfile.NamedTemporaryFile('w', suffix='.cpp') as f:
        f.write('int main (int argc, char **argv) { return 0; }')
        try:
            compiler.compile([f.name], extra_postargs=[flagname])
        except setuptools.distutils.errors.CompileError:
            return False
    return True

def cpp_flag(compiler):
    """Return the -std=c++[11/14] compiler flag.
    The c++14 is prefered over c++11 (when it is available).
    """
    if has_flag(compiler, '-std=c++14'):
        return '-std=c++14'
    elif has_flag(compiler, '-std=c++11'):
        return '-std=c++11'
    else:
        raise RuntimeError('Unsupported compiler -- at least C++11 support '
                           'is needed!')

class Build_Ext(build_ext):
    c_opts = {
        "msvc":["/EHsc"],
        "unix":[]
    }
    if sys.platform == "darwin":
        c_opts["unix"].extend(["-stdlib=libc++","-mmacosx-version-min=10.7"])
    
    def build_extensions(self):
        ct = self.compiler.compiler_type
        opts = self.c_opts.get(ct,[])
        if ct == "unix":
            opts.append("-DVERSION_INFO='%s'" %self.distribution.get_version())
            opts.append('-DSITE_PACKAGE_PATH="%s"'% SITE_PACKAGE_DIR)
            opts.append(cpp_flag(self.compiler))
            opts.append("-O3")
            if has_flag(self.compiler, '-fvisibility=hidden'):
                opts.append('-fvisibility=hidden')
            # 增加 mac windows
        for ext in self.extensions:
            ext.extra_compile_args = opts
        build_ext.build_extensions(self)

install_requires = ["pybind11>2.2"]


extras_require = {
    'test': ['spec==1.4.1']
}

if sys.version_info[0] < 3:
    extras_require["test"].append("pathlib2")

setup(
    name="libanalysepy",
    version="1.0.0",
    author="askr-ssy",
    ext_modules=ext_modules,
    install_requires=install_requires,
    packages=["libanalysepy","analyse.dict"],
    packages_data={
        "analyse.dict":["*.utf8","*.txt"]
    },
    include_package_data=True,
    extras_require=extras_require,
    cmdclass={"build_ext":Build_Ext},
    zip_safe=False
)