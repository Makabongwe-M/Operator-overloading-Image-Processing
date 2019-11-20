## Basic image operations using operator overloading

Author: Makabongwe Nkabinde

operation with two images can be any of these {-a(add), -s(subtract), -l(mask)}

example:
  executable -l Lenna_standard.pgm Lenna_hat_mask.pgm maskOutput.pgm

threshold operates on one Image.
threshold is an integer
example:
    executable -t shrek_rectangular.pgm 150 threshold.pgm

invert operation only works on 3 arguments.
example:
executable -i Lenna_standard.pgm invert.pgm

The resulting image will be automatically saved once the operation is done.
