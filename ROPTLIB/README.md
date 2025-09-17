# ROPTLIB (Riemannian Manifold Optimization Library)

This package is used to optimize a smooth cost function defined on a Riemannian manifold. Many state of the art algorithms are included. The package is written in C++ using the standard linear algebra libraries, BLAS and LAPACK. It can be used alone in C++ environment or in Matlab or in Julia. More meaningful and smaller computational time is obtained when compared with code only in Matlab. Users need only provide a cost function, gradient function, an action of Hessian (if a Newton method is used) in Matlab, Julia or C++ and parameters to control the optimization, e.g., the domain manifold, the algorithm, stopping criterion.

This package was developed by [Wen Huang](https://www.math.fsu.edu/~whuang2/index.html). For more information, visit the [ROPTLIB project homepage](https://www.math.fsu.edu/~whuang2/Indices/index_ROPTLIB.html).

## Version

Base upstream version: **ROPTLIB v0.9**

## Changes (since upstream v0.9)

Current applied modifications:

- Added `<string.h>` to `Others/def.h` to explicitly declare `strcmp` (avoids implicit declaration warnings on some compilers).
