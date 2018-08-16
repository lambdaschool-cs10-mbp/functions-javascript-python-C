def functions():
    elements = [1, 2, 3, 4, 5, 6]

    # filter
    evenList = filter(lambda element: element % 2 == 0, elements)
    # print(evenList)

    # reduce
    from functools import reduce
    total = reduce(lambda acc, cur: acc + cur, elements)
    # print(total)

    # map
    cubed = list(map(lambda element: element ** 3, elements))
    print(cubed)


if __name__ == '__main__':
    functions()
