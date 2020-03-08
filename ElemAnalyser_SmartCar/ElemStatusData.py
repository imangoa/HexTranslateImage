


class ElemStatusData:
    # --- private members ---
    bindata = 0


    def __init__(self, data):
        self.bindata = data


    def getpix(self, row, col):
        # mask = pow(2, (col % 8))    # 存储顺序是字节的0-7
        mask = pow(2, 7 - (col % 8))  # 存储顺序是字节的7-0
        block = int(self.bindata[row][col >> 3])
        return True if mask & block else False