# push_swap

Занятная задачка на алгоритм сортировки определёнными командами.

Вводится через командную строку стек а, есть в распоряжении пустой стек б, список команд, доступных для сортировки:

sa (swap a): поменять местами первые два элемента в стеке а.
Ничего не делать, если только один элемент или они отсутствуют.

sb (swap b): поменять местами первые два элемента в стеке b.
Ничего не делать, если только один элемент или они отсутствуют.

ss : sa и sb одновременно.

pa (push a): переместить первый элемент стека b на первое место стека a.
Ничего не делать, если стек b пустой.

pb (push b): переместить первый элемент стека a на первое место стека b.
Ничего не делать, если стек a пустой.

ra (rotate a): перекинуть первый элемент стека а в конец стека а.

rb (rotate b): перекинуть первый элемент стека b в конец стека b.

rr : ra и rb одновременно.

rra (reverse rotate a): перекинуть последний элемент стека а в начало стека а.

rrb (reverse rotate b): перекинуть последний элемент стека b в начало стека b.

rrr : rra и rrb одновременно.

#Запуск: make && ./push_swap 3 2 6 5 1

#Запуск тестера: make && make bonus $$ ./push_swap 3 2 6 5 1 | ./checker 3 2 6 5 1
