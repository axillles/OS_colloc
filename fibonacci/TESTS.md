# Результаты запуска юнит-тестов для Fibonacci

Этот документ содержит результаты выполнения тестов для функции генерации чисел Фибоначчи, реализованной в проекте. Тесты выполнены с использованием Google Test.

---

## Вывод тестов
[==========] Running 5 tests from 1 test suite.

[----------] 5 tests from FibonacciTest


[ RUN      ] FibonacciTest.SingleElement

[       OK ] FibonacciTest.SingleElement (0 ms)

[ RUN      ] FibonacciTest.FiveElements

[       OK ] FibonacciTest.FiveElements (0 ms)

[ RUN      ] FibonacciTest.ZeroInput

[       OK ] FibonacciTest.ZeroInput (0 ms)

[ RUN      ] FibonacciTest.Overflow

[       OK ] FibonacciTest.Overflow (0 ms)

[ RUN      ] FibonacciTest.TenElements

[       OK ] FibonacciTest.TenElements (0 ms)

[----------] 5 tests from FibonacciTest (0 ms total)

[==========] 5 tests from 1 test suite ran. (0 ms total)

[  PASSED  ] 5 tests.

---

## Описание тестов

1. **FibonacciTest.SingleElement**
   - Проверяет генерацию одного числа Фибоначчи (n = 1).
   - Ожидаемый результат: `[0]`.
   - Статус: Успешно.

2. **FibonacciTest.FiveElements**
   - Проверяет генерацию первых пяти чисел Фибоначчи (n = 5).
   - Ожидаемый результат: `[0, 1, 1, 2, 3]`.
   - Статус: Успешно.

3. **FibonacciTest.ZeroInput**
   - Проверяет обработку исключения при вводе n = 0.
   - Ожидаемый результат: Выброс `std::invalid_argument`.
   - Статус: Успешно.

4. **FibonacciTest.Overflow**
   - Проверяет обработку переполнения для большого n (n = 94).
   - Ожидаемый результат: Выброс `std::overflow_error`.
   - Статус: Успешно.

5. **FibonacciTest.TenElements**
   - Проверяет генерацию первых десяти чисел Фибоначчи (n = 10).
   - Ожидаемый результат: `[0, 1, 1, 2, 3, 5, 8, 13, 21, 34]`.
   - Статус: Успешно.

---

## Итог

- **Всего тестов**: 5
- **Успешно пройдено**: 5
- **Время выполнения**: 0 мс

Все тесты успешно завершены, что подтверждает корректность реализации функции `getFirstNFibonacciNumbers`.
