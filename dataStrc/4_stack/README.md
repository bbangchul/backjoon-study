# 4. Stack (스택)

스택은 마지막에 넣은 원소를 먼저 꺼내는 LIFO 자료구조입니다.
기존 `3_queue`처럼 구현과 응용을 주제별 폴더로 나눴습니다.

| 폴더 | 내용 | 알고리즘 |
| --- | --- | --- |
| `1_arrayStack배열스택` | 배열 스택과 실행 예제 | E.1–E.2 |
| `2_stackApp문자열뒤집기` | 배열 스택으로 한 줄 뒤집기 | E.3 |
| `3_ptrStack포인터스택` | 연결 노드 스택과 실행 예제 | E.5–E.7 |
| `4_stackApp괄호검사` | 포인터 스택으로 괄호 짝 검사 | E.8 |

E.4는 제공된 코드가 없어 별도 파일을 만들지 않았습니다.

## top의 의미

배열 스택에서 `top`은 다음 삽입 위치입니다. `Push`는 `storage[top++]`에 저장하고,
`Pop`은 `storage[--top]`을 반환합니다. `Top`은 `storage[top - 1]`만 읽습니다.
`top == 0`이면 비어 있고, `top == size`이면 가득 찼습니다.
배열 용량은 생성 시 0 이상의 값으로 지정합니다.

포인터 스택에서 `top`은 마지막으로 삽입한 노드를 가리킵니다.
`Push`는 새 노드를 기존 top 앞에 연결하고, `Pop`은 top을 다음 노드로 이동한 뒤
기존 노드를 해제합니다. `top == 0`이면 비어 있습니다.

두 구현 모두 제공된 코드대로 빈 스택의 `Pop`과 `Top`은 0을 반환합니다.
실제 데이터 0과 구분하려면 먼저 `IsEmpty()`를 확인해야 합니다.
소멸자를 추가해 남은 메모리를 해제하고, 포인터의 중복 해제를 막기 위해 복사를 금지했습니다.
각 폴더의 `main.cpp`는 필요한 헤더와 구현을 모두 포함한 통합본입니다.
`node.h`, `stack.h`, `stack.cpp` 영역의 시작과 끝을 주석으로 표시했습니다.
기존 헤더·구현 파일과 `reverse.cpp`, `wff.cpp`는 유지했습니다.
통합본은 `main.cpp` 하나만 컴파일합니다. `stack.cpp`를 함께 링크하면 중복 정의가 발생합니다.

## 컴파일 및 실행

아래 명령은 `4_stack` 폴더에서 실행합니다. C++11 이상이 필요합니다.

```sh
c++ -std=c++11 1_arrayStack배열스택/main.cpp -o /tmp/arrayStack
/tmp/arrayStack

c++ -std=c++11 2_stackApp문자열뒤집기/main.cpp -o /tmp/stackReverse
printf 'hello\n' | /tmp/stackReverse

c++ -std=c++11 3_ptrStack포인터스택/main.cpp -o /tmp/ptrStack
/tmp/ptrStack

c++ -std=c++11 4_stackApp괄호검사/main.cpp -o /tmp/stackWff
printf '[ { { } } { } ]\n' | /tmp/stackWff
printf '([)]\n' | /tmp/stackWff
```

문자열 예제의 최종 출력은 `olleh`, 괄호 예제의 최종 출력은 각각
`WFF!!`, `Not a WFF!!`입니다.

문자열 뒤집기는 원본처럼 용량 30이며 초과 입력은 오류로 처리합니다.
바이트 단위로 뒤집으므로 영문 등 단일 바이트 문자열을 사용합니다.
괄호 검사는 `()`, `[]`, `{}`의 중첩과 짝을 검사하며 다른 문자는 무시합니다.
두 응용은 줄바꿈 또는 EOF에서 입력을 마칩니다. 빈 괄호 식은 WFF로 판정합니다.

## main의 함수 테스트 출력

모든 `main()`은 `IsEmpty`, `Push`, `IsFull`, `Top`, `Pop` 결과를 짧게 출력합니다.
10, 20을 넣고 20, 10 순서로 꺼냅니다. 배열 테스트 용량은 2이므로
삽입 후 `IsFull`은 true이며, 포인터 스택은 false입니다.
문자열 뒤집기와 괄호 검사는 함수 테스트 다음에 실행됩니다.
