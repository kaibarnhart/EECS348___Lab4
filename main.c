#include <stdio.h>

void calculate_combinations(int score) {
    int td_2pt, td_fg, td, fg, safety;

    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

    for (td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        for (td_fg = 0; td_fg * 7 + td_2pt * 8 <= score; td_fg++) {
            for (td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= score; td++) {
                for (fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; fg++) {
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; safety++) {
                        if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // Terminate if the score is 1 or less
        if (score <= 1) {
            printf("Exiting the program.\n");
            break;
        }

        calculate_combinations(score);
    }

    return 0;
}