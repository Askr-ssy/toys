#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>
namespace py = pybind11;
using namespace std;
class Caculate {
public:
  Caculate() {}
  vector<int16_t> Pi(int N) {
    long a[2] = {956, 80}, b[2] = {57121, 25}, i = 0, j, k, p, q, r, s = 2, t,
         u, v, M = 10000;
    N = N / 4 + 3;
    std::vector<int16_t> pi(N, 0);
    std::vector<int16_t> e(N, 0);
    while (--s + 1) {
      for (e[0] = a[k = s], i = N; --i;) e[i] = 0;
      for (q = 1; j = i - 1, i < N; e[i] ? 0 : ++i, q += 2, k = !k)
        for (r = v = 0; ++j < N; pi[j] += k ? u : -u)
          u = (t = v * M + (e[j] = (p = r * M + e[j]) / b[s])) / q,
          r = p % b[s], v = t % q;
    }
    while (--i)
      (pi[i] = (t = pi[i] + s) % M) < 0 ? pi[i] += M, s = t / M - 1 : s = t / M;
    return pi;
  }
};

PYBIND11_MODULE(Caculatecpp, ca) { 
    py::class_<Caculate>(ca,"Caculate")
        .def(py::init<>())
        .def("Pi",&Caculate::Pi);
}