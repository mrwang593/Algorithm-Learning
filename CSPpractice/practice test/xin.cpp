#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef vector<long long> Poly;

Poly poly_add(const Poly& a, const Poly& b) {
    Poly res(21, 0);
    for (int i = 0; i < 21; i++) {
        res[i] = a[i] + b[i];
    }
    return res;
}

Poly poly_mult(const Poly& a, const Poly& b) {
    Poly res(21, 0);
    for (int i = 0; i < 21; i++) {
        if (a[i] == 0) continue;
        for (int j = 0; j < 21 - i; j++) {
            res[i + j] += a[i] * b[j];
        }
    }
    return res;
}

void skip_to_end(const vector<string>& tokens, int& i) {
    int depth = 0;
    while (i < tokens.size()) {
        if (tokens[i] == "loop") {
            depth++;
        } else if (tokens[i] == "end") {
            if (depth == 0) {
                i++;
                return;
            } else {
                depth--;
            }
        }
        i++;
    }
}

tuple<Poly, int, bool, bool> parse(const vector<string>& tokens, int start);

tuple<Poly, int, bool, bool> parse_statement(const vector<string>& tokens, int i) {
    if (tokens[i] == "op") {
        string x_str = tokens[i + 1];
        Poly p(21, 0);
        if (x_str == "n") {
            p[1] = 1;
        } else {
            p[0] = stoll(x_str);
        }
        return make_tuple(p, i + 2, false, false);
    } else if (tokens[i] == "break") {
        return make_tuple(Poly(21, 0), i + 1, true, false);
    } else if (tokens[i] == "continue") {
        return make_tuple(Poly(21, 0), i + 1, false, true);
    } else if (tokens[i] == "loop") {
        string x_str = tokens[i + 1];
        int next_i = i + 2;
        auto [body_poly, next_i_after_body, body_break, body_continue] = parse(tokens, next_i);
        Poly x_poly(21, 0);
        if (x_str == "n") {
            x_poly[1] = 1;
        } else {
            x_poly[0] = stoll(x_str);
        }
        Poly loop_poly;
        if (body_break) {
            loop_poly = body_poly;
        } else {
            loop_poly = poly_mult(x_poly, body_poly);
        }
        return make_tuple(loop_poly, next_i_after_body, false, false);
    } else {
        return make_tuple(Poly(21, 0), i + 1, false, false);
    }
}

tuple<Poly, int, bool, bool> parse(const vector<string>& tokens, int start) {
    Poly current(21, 0);
    int i = start;
    bool has_break = false;
    bool has_continue = false;
    while (i < tokens.size() && tokens[i] != "end") {
        if (tokens[i] == "op" || tokens[i] == "loop" || tokens[i] == "break" || tokens[i] == "continue") {
            auto [p, next_i, b, c] = parse_statement(tokens, i);
            current = poly_add(current, p);
            i = next_i;
            if (b || c) {
                has_break = b;
                has_continue = c;
                skip_to_end(tokens, i);
                break;
            }
        } else {
            i++;
        }
    }
    return make_tuple(current, i, has_break, has_continue);
}

void output_poly(const Poly& poly) {
    bool first = true;
    for (int exp = 20; exp >= 0; exp--) {
        if (poly[exp] == 0) continue;
        if (!first) {
            cout << "+";
        }
        first = false;
        if (exp == 0) {
            cout << poly[exp];
        } else {
            if (poly[exp] != 1) {
                cout << poly[exp];
            }
            cout << "n";
            if (exp > 1) {
                cout << "^" << exp;
            }
        }
    }
    if (first) {
        cout << "0";
    }
    cout << endl;
}

int main() {
    string line;
    vector<string> tokens;
    while (getline(cin, line)) {
        istringstream iss(line);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
    }
    if (tokens.empty()) {
        cout << "0" << endl;
        return 0;
    }
    int start_index = 0;
    if (tokens[0] == "begin") {
        start_index = 1;
    }
    auto [poly, next_i, has_break, has_continue] = parse(tokens, start_index);
    output_poly(poly);
    return 0;
}
