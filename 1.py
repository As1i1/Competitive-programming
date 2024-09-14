v sys import stdin

alpha = input()
alpha = "(" + alpha + ")"
implies = " \\to "
res = []


def print_item(s):
    res.append("\\item " + s)


def aksioma(delta):  # аксиома или гипотеза
    print_item("$" + delta + implies + alpha + implies + delta + "$")
    print_item("$" + delta + "$")
    print_item("$" + alpha + implies + delta + "$")


def alpha_():
    print_item("$" + alpha + implies + alpha + "$")  # Очев


def MP(delta1, delta2):
    print_item(
        "$" + "(" + alpha + implies + delta1 + ")"
        + implies +
        "(" + alpha + implies + delta1 + implies + delta2 + ")"
        + implies +
        "(" + alpha + implies + delta2 + ")" + "$")
    print_item("$" + "(" + alpha + implies + delta1 + implies + delta2 + ")"
               + implies +
               "(" + alpha + implies + delta2 + ")" + "$")
    print_item("$" + alpha + implies + delta2 + "$")


q = input()
t = input()
input()
while t != "end":
    q = "(" + q + ")"
    if t == "1":
        aksioma(q)
    elif t == "=":
        alpha_()
    else:
        t = "(" + t + ")"
        MP(q, t)
    q = input()
    t = input()
    input()
print("\n".join(res))

"""
a = a + 0
a = a + 0
=

a = a + 0 \to a' = (0 + a)'
1

a = a + 0
a' = (0 + a)'

\forall p. \forall q. p = q \to q = p
1

(\forall p. \forall q. p = q \to q = p) \to (\forall q. a' = q \to q = a')
1

\forall p. \forall q. p = q \to q = p
\forall q. a' = q \to q = a'

(\forall q. a' = q \to q = a') \to a' = (0 + a)' \to (0 + a)' = a'
1

\forall q. a' = q \to q = a'
a' = (0 + a)' \to (0 + a)' = a'

a' = (0 + a)'
(0 + a)' = a'

0 + a' = (0 + a)'
1

(\forall p. \forall q. p = q \to q = p) \to (\forall q. 0 + a' = q \to q = 0 + a')
1

\forall p. \forall q. p = q \to q = p
\forall q. 0 + a' = q \to q = 0 + a'

(\forall q. 0 + a' = q \to q = 0 + a') \to 0 + a' = (0 + a)' \to (0 + a)' = 0 + a'
1

\forall q. 0 + a' = q \to q = 0 + a'
0 + a' = (0 + a)' \to (0 + a)' = 0 + a'

0 + a' = (0 + a)'
(0 + a)' = 0 + a'

(0 + a)' = a' \to (0 + a)' = 0 + a' \to a' = 0 + a'
1

(0 + a)' = a'
(0 + a)' = 0 + a' \to a' = 0 + a'

(0 + a)' = 0 + a'
a' = 0 + a'
"""