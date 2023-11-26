class Water {
public:
    int temp;
    Water(int temper) {
        temp = temper;
    }
};

class Teapot {
public:
    int temp1;
    Teapot(class Water water1) {
        temp1 = water1.temp;
    }

    bool is_boiling() {
        if (temp1 >= 100) {
            return true;
        }
        return false;
    }

    int heat_up(int heat) {
        temp1 += heat;
        return temp1;
    }
};
