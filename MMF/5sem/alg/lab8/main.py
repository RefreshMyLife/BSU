from graph import *
import sys

'''
    проверка на двусвязность
    
        1. найти точку с наибольшей степенью и убрать
            если есть одиночные:
                соединяем в цикле одиночную с вершиной наименьшей степени
        2. запустить поиск из соседних к ней(удаляемой). получим массив компонент типа
        ([узлы], элемент списка слева с минимальной степенью)
        3. если несколько компонент - связать через вершины с минимальной степенью
        и максимально удалённые от удаляемой вершины из (1)
        4. удаляем соединённые компоненты из графа и повторяем (1),
        если соединённые компоненты не дают исходный граф
'''

if __name__ == '__main__':
    A = create_matrix_from_file("4")
    print_graph(A)
    print_graph(check_double_coherence(A))
    sys.exit(0)
