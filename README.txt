Sawubona (Hello)

A few things I found to be noteworthy:
  -All operations except for one (invert operation) work on 4 arguemnts:

    -Should you wish to perform an add, subtract, mask or threshold, please enter the following on command line:
        -executable operation Image1 Image2 OutputImage
          -executable = imageops
          -operation can be any of these {-a(add), -s(subtract), -l(mask)}
          -Example:
              ./imageops -l Lenna_standard.pgm Lenna_hat_mask.pgm maskOutput.pgm

        -threshold is a special case in that it operates on one Image. Please enter the following on command line:
            -executable operation Image threshold OutputImage
            -executable  = imageops
            -operation is -t, of course
            -threshold is an integer
            -Example:
                ./imageops -t shrek_rectangular.pgm 150 threshold.pgm


    -The invert operation only works on 3 arguments. Therefore:
      -executable operation Image OutputImage
      -executable  = imageops
      -operation is -i, of course
      Example:
        -./imageops -i Lenna_standard.pgm invert.pgm
  -The resulting image will be automatically saved once the operation is done.

Usalekahle (Goodbye)
