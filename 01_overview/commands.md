# Kernel Overview & Related Commands

This document covers essential commands for interacting with the Linux Kernel and managing kernel modules.

## 1. System Information

### `uname`
Prints system information.
- `uname -a`: Print all information (kernel name, network node hostname, kernel release, kernel version, machine hardware name, processor type, hardware platform, operating system).
- `uname -r`: Print the kernel release.

Example:
```bash
$ uname -r
5.15.0-76-generic
```

### `dmesg`
Prints or controls the kernel ring buffer. This is the primary way to see messages printed by kernel modules (using `printk`).
- `dmesg | grep "Hello"`: Filter messages.
- `dmesg -C`: Clear the ring buffer.
- `dmesg -w`: Follow new messages (like `tail -f`).

## 2. Kernel Module Management

### `lsmod`
Shows the status of modules currently loaded in the Linux Kernel.
- Format: `Module Size Used by`

Example:
```bash
$ lsmod | head -3
Module                  Size  Used by
nls_utf8               16384  1
isofs                  49152  1
```

### `insmod`
Inserts a module into the kernel. Requires root privileges.
- syntax: `sudo insmod <module_name.ko>`

Example:
```bash
$ sudo insmod hello_world.ko
```

### `rmmod`
Removes a module from the kernel. Requires root privileges.
- syntax: `sudo rmmod <module_name>` (note: usually without .ko extension, just the module name)

Example:
```bash
$ sudo rmmod hello_world
```

### `modinfo`
Shows information about a Linux Kernel module (author, license, parameters, description).
- syntax: `modinfo <module_name.ko>`

Example:
```bash
$ modinfo hello_world.ko
filename:       /path/to/hello_world.ko
license:        GPL
author:         Student
description:    A simple Hello World module
srcversion:     ...
depends:        
retpoline:      Y
name:           hello_world
```

## 3. Advanced Module Loading

### `modprobe`
A more intelligent command to add or remove modules regarding this dependency. It looks in the module directory `/lib/modules/$(uname -r)` for all the modules and other files.
- `sudo modprobe <module_name>`: Load module and dependencies.
- `sudo modprobe -r <module_name>`: Remove module and dependencies.
