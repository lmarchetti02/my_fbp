"""
Generate the data to test the C library
"""

import numpy as np

SIZE = 2**10


def main():
    """Main function"""
    rng = np.random.default_rng()
    x = rng.random(SIZE)

    np.savetxt(
        "data_fft.txt",
        x,
        fmt="%.15f",
    )


if __name__ == "__main__":
    main()
