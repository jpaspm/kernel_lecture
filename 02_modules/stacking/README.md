# Kernel Module Stacking Example

This project demonstrates **Kernel Module Stacking**, where one kernel module exports a function (symbol) that is used by another module. This mechanism allows for creating dependencies between modules and sharing functionality within the kernel space.

## Files

*   **`avg_mod.c`**: The "provider" module.
    *   Defines a function `calculate_average(int a, int b)`.
    *   Exports this function using `EXPORT_SYMBOL`, making it available to other kernel modules.
*   **`calc_mod.c`**: The "consumer" module.
    *   Declares the external function `calculate_average`.
    *   Calls `calculate_average` within its initialization function.

## Prerequisites

*   Linux headers for your current kernel version.
*   GCC and Make.

## Building the Modules

To compile the modules, simply run:

```sh
make
```

This will generate `avg_mod.ko` and `calc_mod.ko`.

## Usage

Since `calc_mod` depends on a symbol provided by `avg_mod`, the order of loading (insertion) and unloading (removal) is critical.

### 1. Load the Modules

You must load `avg_mod` first so the symbol is present in the kernel symbol table.

```sh
# Load the provider module
sudo insmod avg_mod.ko

# Load the consumer module
sudo insmod calc_mod.ko
```

If you try to load `calc_mod.ko` without loading `avg_mod.ko` first, you will get an "Unknown symbol" error.

### 2. Verify Output

Check the kernel log (dmesg) to see the output from the modules:

```sh
sudo dmesg | tail
```

Expected output:
```text
[ ... ] Avg mod loaded: function calculate_average exported.
[ ... ] Calc mod loaded: Average of 10 and 20 is 15
```

### 3. Unload the Modules

You must remove the dependent module (`calc_mod`) first.

```sh
# Remove the consumer module
sudo rmmod calc_mod

# Remove the provider module
sudo rmmod avg_mod
```

If you try to remove `avg_mod` while `calc_mod` is still loaded, the kernel will prevent it because the module is in use.

## Cleaning Up

To clean the build artifacts:

```sh
make clean
```
