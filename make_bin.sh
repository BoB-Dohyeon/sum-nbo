#!/bin/bash
echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
echo -n -e \\x00\\x00\\x00\\xc8 > two-hundred.bin

