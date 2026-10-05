# efitest

v0.1a, October 2026

## What is this? 

`efitest` demonstrates how to build and deploy a bare-metal (no operating
system) program on a PC-type computer that supports 64-bit EFI (or UEFI)
booting. Almost any PC-like computer with an Intel or AMD CPU from the last
fifteen years should work. 

The EFI program itself is a trivial one -- it just reads input from the keyboard
and echoes it back to the console. However, it does demonstrate some important
features of EFI programming.

`efitest` is designed to be built on a 64-bit Linux system, with `gnu-efi`
development tools in place (`apt install gnu-efi`). You'll also need
`mtools` for manipulating the DOS-like floppy disk image that will 
host the EFI program. 

To build the bootable CD/USB image, you'll need `xorriso`. `genisoimage` 
and `mkisofs` might work on some systems, but their EFI support seems to be
limited on some Linux distributions.

## Building the boot image

If you have all the prerequisites, `make` should do all the work.  The result
will be a bootable disk image `test.iso`. 

## Testing with VirtualBox

Create a VirtualBox machine of type `Other/Unknown (64-bit)`. In the Settings
dialog, under System, check `Enable EFI`, but do not enable Secure Boot. 

Create a virtual DVD drive, using `test.iso` as the image. Boot the virtual
machine. 

## Making a bootable USB stick

Plug in a USB stick, and copy the `test.iso` to the raw disk device -- not to a
partition.  For example:

```
dd if=test.iso of=/dev/sdb
```

Naturally, any other data on the device will be overwritten, so don't
use `sdb` unless you're sure it's appropriate.

## Testing on a real computer

Plug in the USB drive, and configure your computer to boot from it. There's 
probably a keystroke that allows you to select the boot device on the fly
(on my Lenovo laptops it's the F12 key).

You'll need to ensure that Secure Boot is disabled. You might (or might not)
need to re-enable it to boot a real operating system.

## More information

See [my website](https:/kevinboone.me/efitest1.html).


