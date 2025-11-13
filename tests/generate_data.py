"""
Generate the data to test the C library
"""

import numpy as np

SIZE = 2**10


def main():
    """Main function"""
    rng = np.random.default_rng()
    x_re = rng.random(SIZE)
    x_im = rng.random(SIZE)

    x = np.vstack((x_re, x_im)).transpose()
    np.savetxt(
        "data_fft.csv",
        x,
        fmt="%.15f",
        delimiter=",",
    )


if __name__ == "__main__":
    main()
