#include <iostream>
#include <stack>
#define COLORENDS "\x1b[0m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define PURPLE "\x1b[38;2;190;82;125m"

void end() {
  std::cout << PURPLE << "Wrong sequence\n" << COLORENDS;
  std::exit(0);
}

int main(int argc, char const *argv[]) {
  char ch;
  std::stack<char> stack;
  std::cin >> ch;
  while (!std::cin.eof()) {
    if (ch == '(' || ch == '[' || ch == '{') {
      stack.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      switch (ch) {
        case ')':
          if (stack.empty() || stack.top() != '(') end();
          break;
        case ']':
          if (stack.empty() || stack.top() != '[') end();
          break;
        case '}':
          if (stack.empty() || stack.top() != '{') end();
          break;
      }
      stack.pop();
    } else {
      std::cerr << RED << "Check symbols\n" << COLORENDS;
      return 0;
    }
    if (!stack.empty()) std::cin >> ch;
  }
  if (stack.empty()) {
    std::cout << GREEN << "Right\n" << COLORENDS;
  } else
    std::cout << PURPLE << "Wrong sequence\n" << COLORENDS;
  return 0;
}
