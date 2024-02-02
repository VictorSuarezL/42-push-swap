# Push Swap

This repository contains the implementation of the Push Swap algorithm.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Push Swap is a sorting algorithm that operates on a stack of integers. It aims to sort the stack in ascending order using a limited set of operations.

This repository provides an implementation of the Push Swap algorithm in C.

## Installation

To use the Push Swap algorithm, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/push-swap.git`
2. Navigate to the project directory: `cd push-swap`
3. Compile the program: `make`
4. Run the program: `./push_swap <list of integers>`

## Usage

The Push Swap algorithm takes a list of integers as input and outputs a series of operations that sorts the integers in ascending order. The available operations are:

- `sa`: Swap the first two elements of the stack A.
- `sb`: Swap the first two elements of the stack B.
- `ss`: Swap the first two elements of both stack A and stack B.
- `pa`: Push the first element of stack B to stack A.
- `pb`: Push the first element of stack A to stack B.
- `ra`: Rotate the stack A (move the first element to the end).
- `rb`: Rotate the stack B (move the first element to the end).
- `rr`: Rotate both stack A and stack B.
- `rra`: Reverse rotate the stack A (move the last element to the beginning).
- `rrb`: Reverse rotate the stack B (move the last element to the beginning).
- `rrr`: Reverse rotate both stack A and stack B.


