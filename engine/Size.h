#ifndef UNTITLED_SIZE_H
#define UNTITLED_SIZE_H

class Size {
    int xExtent;
    int yExtent;

public:
    Size(int xExtent, int yExtent);

    int x() const { return xExtent; };

    int y() const { return yExtent; };
};

#endif //UNTITLED_SIZE_H
