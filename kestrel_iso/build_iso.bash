#!/bin/bash

LIMINE_CFG=$1
KESTREL_ISO=$2
KESTREL=$3

for PATH in $4 $5 $6
do
    if [[ $(/usr/bin/basename $PATH) == "limine.sys" ]]
    then
        LIMINE_SYS=$PATH
    elif [[ $(/usr/bin/basename $PATH) == "limine-cd.bin" ]]
    then
        LIMINE_CD=$PATH
    elif [[ $(/usr/bin/basename $PATH) == "limine-cd-efi.bin" ]]
    then
        LIMINE_CD_EFI=$PATH
    else
        echo "Error: Unrecognized path $PATH" 1>&2
        exit 1
    fi
done

if [[ -z $LIMINE_SYS  ]]
then
    echo "Error: Missing limine.sys" 1>&2
    exit 1
elif [[ -z $LIMINE_CD  ]]
then
    echo "Error: Missing limine-cd.bin" 1>&2
    exit 1
elif [[ -z $LIMINE_CD_EFI  ]]
then
    echo "Error: Missing limine-cd-efi.bin" 1>&2
    exit 1
fi

KESTREL_ISO_ROOT="$(/usr/bin/dirname $KESTREL_ISO)/root"

/usr/bin/rm -rf $KESTREL_ISO_ROOT
/usr/bin/mkdir -p $KESTREL_ISO_ROOT
/usr/bin/cp \
    $KESTREL \
    $LIMINE_CFG \
    $LIMINE_SYS \
    $LIMINE_CD \
    $LIMINE_CD_EFI \
    $KESTREL_ISO_ROOT

/usr/bin/xorriso \
    -as mkisofs \
    -b $(/usr/bin/basename $LIMINE_CD) \
    -no-emul-boot \
    -boot-load-size 4 \
    -boot-info-table \
    --efi-boot $(/usr/bin/basename $LIMINE_CD_EFI) \
    -efi-boot-part \
    --efi-boot-image \
    --protective-msdos-label $KESTREL_ISO_ROOT \
    -o $KESTREL_ISO

/usr/bin/rm -rf $KESTREL_ISO_ROOT
