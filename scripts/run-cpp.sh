#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "用法: ./scripts/run-cpp.sh \"题目目录或 main.cpp 路径\""
  exit 1
fi

target="$1"
if [[ -d "$target" ]]; then
  source_file="$target/main.cpp"
else
  source_file="$target"
fi

if [[ ! -f "$source_file" ]]; then
  echo "未找到 C++ 源文件: $source_file"
  exit 1
fi

binary="/tmp/leetcode-solution"
echo "正在编译: $source_file"
g++ "$source_file" -std=c++17 -O2 -Wall -Wextra -o "$binary"

echo "编译成功，请按题解中的输入格式输入数据："
"$binary"
