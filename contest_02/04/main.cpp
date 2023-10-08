long nod(long a, long b) {
    while (b != 0) {
        std::tie(a, b) = std::make_tuple(b, a % b);
    }
    return a;
}

std::tuple<long, long> reduce(long a, long b) {
    long nod1 = nod(a, b);
    if (a > 0 && b < 0) {
        a /= nod1;
        b /= nod1;
        a = a * (-1);
        b = b * (-1);
    }
    else {
        a /= nod1;
        b /= nod1;
    }
    return std::tuple{ a, b };
}

std::tuple <long, long, long> find_lcm(long a, long b) {
    long num = nod(a, b);
    long lcm = (a * b) / num;
    long a1 = b / num;
    long b1 = a / num;
    return std::tuple{ lcm, a1, b1 };
}
