#include <stdio.h>

/* gets the two sets, a, b, and there length,
   and prints the union between them */
void print_union(int a[], int b[], int length_a, int length_b) {
    // initialize and defines the flag "is_empty" to "1"
    int is_empty = 1;

    // if set "a" is an empty set:
    if (length_a < 1) {
        printf("{");
        // defines the flag, is_empty, to 0, to acknowledge that
        // set "a" is an empty set
        is_empty = 0;
    }

    // if set "a" is not an empty set:
    else {
        // the first element in the array
        printf("{%d ", a[0]);
    }

    // iterate over the array "a", and prints all the elements in array "a",
    // starting from the second element, in the format ", a[i]"
    for (int i = 1; i < length_a; i++) {
        printf("%d ", a[i]);
    }

    // iterates over the array b
    for(int i = 0; i < length_b; i++) {
        // initialize and defines the flag "is_equal" to "0"
        int is_equal = 0;

        // iterate over the array "a", such that if there is element that is a
        // common to a, b, changes the flag, is_equal, to 1, to acknowledge that
        // "b[i] is a common element in a, b,
        // so we have already printed it earlier
        for (int j = 0; j < length_a; j++) {
            if (b[i] == a[j]) {
                is_equal = 1;
            }
        }

        // if there is no common element to "b[i]", in set "a":
        if (is_equal == 0) {
            // if set "a" is an empty set(according to the flag "is_empty"):
            if (is_empty == 0) {
                printf("%d ", b[i]);
                // changes the flag "is_empty" to "1", so we will never enter
                // this "if" statement again
                is_empty = 1;

            // (if set "a" is not an empty set) ||
            // (we have changed the flag "is_empty" already):
            } else {
                printf("%d ", b[i]);
            }
        }
    }

    printf("}");
}

/* gets the two, sorted, sets, a, b, and there length,
   and prints the union between them */
void print_union_sortedArrays(int a_sorted[], int b_sorted[],
                              int length_a, int length_b) {
    // initialize an array c, at a length of the two arrays a, b
    int c_sorted[length_a + length_b];

    int i = 0;
    int j = 0;

    printf("{");

    // iterate over the elements in arrays a, b:
    for (int k = 0; k < length_a + length_b; k++) {
        // if there are more elements in array "a", than array b:
        if (length_a > length_b) {
            // if we have not reached the end of array "a",
            // but we have reached the end of array "b",
            // ||
            // the element in array "a" at i, is not greater than j in b:
            if ((i < length_a) && ((j >= length_b) ||
                                   (a_sorted[i] <= b_sorted[j]))) {
                // defines the element at k in array c to element i in "a",
                // and then rise i by 1
                c_sorted[k] = a_sorted[i++];
            } else if (j < length_b) {
                // defines the element at k in array c to element j in "b",
                // and then rise j by 1
                c_sorted[k] = b_sorted[j++];
            }
        } else {
            // if we have not reached the end of array "b",
            // but we have reached the end of array "a",
            // ||
            // the element in array "b" at j, is not greater than i in a:
            if ((j < length_b) && ((i >= length_a) ||
                                   (b_sorted[j] <= a_sorted[i]))) {
                // defines the element at k in array c to element j in "b",
                // and then rise j by 1
                c_sorted[k] = b_sorted[j++];
            } else if (i < length_a) {
                // defines the element at k in array c_sorted to
                // element i in a_sorted, and then rise i by 1
                c_sorted[k] = a_sorted[i++];
            }
        }

        // after we have defined the element k in array "c_sorted",
        // we check if we are in the first iteration of the for loop,
        // ||
        // the element we defined in index k is not equal to the previous
        // element, to make sure that we are not printing duplicates
        if ((k == 0) || (c_sorted[k] != c_sorted[k - 1])) {
            printf("%d ", c_sorted[k]);
        }
    }

    printf("}");
}

/* gets the two sets, a, b, and there length,
   and prints the intersect between them */
void print_intersect(int a[], int b[], int length_a, int length_b) {
    // if at least one of the sets is an empty set:
    if ((length_a < 1) || (length_b < 1)) {
        printf("{}");
    } else {
        printf("{");

        // initialize and defines the flag "is_first" to "0"
        int is_first = 0;

        // iterates over the array b
        for(int i = 0; i < length_b; i++) {
            // initialize and defines the flag "is_equal" to "0"
            int is_equal = 0;

            // iterate over the array "a", such that if there is element
            // that is a common to a, b, changes the flag, is_equal, to 1,
            // to acknowledge that "b[i]" is a common element in a, b
            for (int j = 0; j < length_a; j++) {
                if (b[i] == a[j]) {
                    is_equal = 1;
                }
            }

            // if there is a common element to "b[i]", in set "a":
            if (is_equal == 1) {
                // if this is the first element to print
                if (is_first == 0) {
                    printf("%d", b[i]);
                    // changes the flag "is_first" to "1", so we will never
                    // enter this "if" statement again
                    is_first = 1;
                } else {
                    printf(" %d ", b[i]);
                }
                // changes the flag "is_equal" to "0"
                is_equal = 0;
            }
        }

        printf("}");
    }
}

/* gets the two, sorted, sets, a, b, and there length,
   and prints the intersect between them */
void print_intersect_sortedArrays(int a_sorted[], int b_sorted[],
                                  int length_a, int length_b) {
    // if at least one of the sets is an empty set:
    if ((length_a < 1) || (length_b < 1)) {
        printf("{}");
    } else {
        // initialize and defines the flag "is_first" to "1"
        int is_first = 1;

        int i = 0;
        int j = 0;

        printf("{");

        // iterates over the elements in arrays a, b,
        // such that we will not go out of bounds of the arrays a, b
        // and according to that the arrays are not empty, so we will enter
        // the loop at least once
        do {
            // if the elements in a, b, are equal:
            if (a_sorted[i] == b_sorted[j]) {
                j++;
                // if this is the first element to print
                if (is_first == 1) {
                    printf("%d ", a_sorted[i++]);
                    // changes the flag "is_first" to "0", so we will never
                    // enter this "if" statement again
                    is_first = 0;
                    // if this is not the first element to print
                } else printf("%d ", a_sorted[i++]);

                // if the element in "a" is smaller than the element in b:
            } else if (a_sorted[i] < b_sorted[j]) {
                i++;
            } else j++;

        } while ((i < length_a) && (j < length_b));

        printf("}");
    }
}

/* gets the two sets, a, b, and there length,
   and prints the difference between them(a/b) */
void print_diff(int a[], int b[], int length_a, int length_b) {
    // if set "a" is an empty set:
    if (length_a < 1) {
        printf("{}");

    // if set b is an empty set, but set "a" is not an empty set:
    } else if (length_b < 1) {
        // then we print all the elements in set a:
        for (int i = 0; i < length_a; i++) {
            if (i == 0) {
                printf("{%d ", a[i]);
            } else {
                printf("%d ", a[i]);
            }
        }
        printf("}");

    // if both sets are not empty sets:
    } else {

        printf("{");

        // initialize and defines the flag "is_first" to "1"
        int is_first = 1;

        // initialize and defines the flag "is_common_element" to "0"
        int is_common_element = 0;

        // iterates over the elements in arrays a:
        for (int i = 0; i < length_a; i++) {
            // iterates over the elements in arrays b:
            for (int j = 0; j < length_b; j++) {
                // if there is a common element to a[i], in set b,
                // changes the flag "is_common_element" to "1"
                // to acknowledge that a[i] is a common element in a, b,
                // so we will not print it
                if (a[i] == b[j]) {
                    is_common_element = 1;
                }
            }

            // if there is no common element to a[i], in set b:
            if (is_common_element == 0) {
                // if this is the first element to print
                if (is_first == 1) {
                    printf("%d ", a[i]);
                    is_first = 0;
                } else {
                    printf("%d ", a[i]);
                }
            }

            // changes the flag "is_common_element" to 0, for the next iteration
            is_common_element = 0;
        }

        printf("}");
    }
}

int main() {
    int a_sorted[9] = {496, 199, 792, 820, 269, 185, 173, 665, 18};
    int b_sorted[8] = {90, 185, 302, 321, 625, 665, 792, 975};
    int length_a = sizeof(a_sorted)/ sizeof (a_sorted[0]);
    int length_b = sizeof(b_sorted)/ sizeof (b_sorted[0]);
    print_diff(a_sorted, b_sorted, length_a, length_b);
    //int i;
    //printf("%d", i);
    extern int j;
    //printf("%d", j);
    return 0;
}
