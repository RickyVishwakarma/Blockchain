# Simple Blockchain Implementation in C++

This project provides a simple implementation of a blockchain in C++ using the Crypto++ library for cryptographic operations.

## Features

- Basic blockchain structure with blocks containing data, previous hash, and timestamp.
- SHA-256 hashing for block integrity.
- Simplified proof-of-work mechanism.
- Chain validation to ensure integrity.

## Prerequisites

- C++11 or later
- Crypto++ library

## Installation

### Installing Crypto++ Library

#### Debian-based systems (like Ubuntu):

```sh
sudo apt-get update
sudo apt-get install libcrypto++-dev
```

Red Hat-based systems:
sh
sudo yum install crypto++-devel

Arch-based systems:
sh
sudo pacman -S crypto++

Alternatively, install from source:
1.Download the Crypto++ library from the official website.
2.Extract the downloaded file.
3.Navigate to the extracted directory and run the following commands:

sh
make
sudo make install

Compiling the Program
1.Clone the repository or download the source code.
2.Navigate to the directory containing the source code.
3.Compile the program with the following command:
sh
g++ -o my_program sampleCodeOriginal.cpp -lcryptopp


---------------------------------------------------------------------------------------------------------------------
Sample Output
yaml

Is chain valid? Yes

Data: Genesis Block
Hash: 2d711642b726b04401627ca9fbac36d08bd28ecdf57a36d9c5b1a82a27bdbad0
Prev Hash: 0
Timestamp: 1618834406323312

Data: Block 1
Hash: 3c5a0f01f36e0b129e2b85f96ff0b6f4465ed4c1d15df13d5a6d52f5eb48b5c5
Prev Hash: 2d711642b726b04401627ca9fbac36d08bd28ecdf57a36d9c5b1a82a27bdbad0
Timestamp: 1618834406323312

Data: Block 2
Hash: 6ae98d7f35781a3b126c1ad1d1eec5a1d6b0c9151f264cd8f7ae8f913bcf6e16
Prev Hash: 3c5a0f01f36e0b129e2b85f96ff0b6f4465ed4c1d15df13d5a6d52f5eb48b5c5
Timestamp: 1618834406323312
