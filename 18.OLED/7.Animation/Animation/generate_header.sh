echo "#ifndef FRAMES_H" > frames.h
echo "#define FRAMES_H" >> frames.h

for file in C/*.c; do
    echo "#include \"$file\"" >> frames.h
done

echo "#endif" >> frames.h

