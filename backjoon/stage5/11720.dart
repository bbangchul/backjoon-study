import 'dart:io';

void main() {
  // 숫자의 개수 입력
  int n = int.parse(stdin.readLineSync()!);

  // 숫자 문자열 입력
  String input = stdin.readLineSync()!;

  int sum = 0;

  for (int i = 0; i < n; i++) {
    // 문자를 정수로 변환
    sum += int.parse(input[i]);
  }

  print(sum);
}