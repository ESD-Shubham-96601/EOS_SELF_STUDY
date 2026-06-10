#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <directory>"
    exit 1
fi

DIR=$1

mkdir -p "$DIR/txt_files"
mkdir -p "$DIR/pdf_files"
mkdir -p "$DIR/c_files"

mv "$DIR"/*.txt "$DIR/txt_files" 2>/dev/null
mv "$DIR"/*.pdf "$DIR/pdf_files" 2>/dev/null
mv "$DIR"/*.c "$DIR/c_files" 2>/dev/null

echo "Files organized successfully."
