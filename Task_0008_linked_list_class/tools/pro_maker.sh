#!/bin/bash

IFS='/' read -a Array <<< `pwd`
Index=${#Array[@]}
ProjectName="${Array[$Index-2]}"

getPath()
{
    Address=`pwd -L`
    cd "$2"
    Result=`pwd -L`
    cd "$Address"
    eval "$1='$Result'"
}

generate()
{
    Filename="$1"
    Path="$2"
    getPath "Path" "$Path"

    rm -f "$Filename"

    printf "INCLUDEPATH += $Path\n" > "$Filename"

    echo >> "$Filename"
    echo "HEADERS+= \\" >> "$Filename"
    find -L $Path -name *.h | awk '{print $1 " \\" }' >> "$Filename"
    find -L $Path -name *.hpp | awk '{print $1 " \\" }' >> "$Filename"
    find -L $Path -name *.typedef | awk '{print $1 " \\" }' >> "$Filename"
    echo >> "$Filename"
    echo "SOURCES+= \\" >> "$Filename"
    find -L $Path -name *.cpp | awk '{print $1 " \\" }' >> "$Filename"
    find -L $Path -name *.inl | awk '{print $1 " \\" }' >> "$Filename"
}

generate "../project/$ProjectName.pri"           "../source"
generate "../test/project/$ProjectName.Test.pri" "../test/source"

