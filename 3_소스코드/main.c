#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LEN 5
#define MAX_TRIES 6

int main() {
    // 1️⃣ 단어 리스트
    const char *words[] = {
        "apple", "table", "chair", "light", "sound", "bread", "water", "sugar", "smile", "laugh", "plant", "stone", "grass", "cloud", "storm", "beach", "heart", "dream", "train", "plane", "house", "mouse", "earth", "flame", "black", "white", "green", "brown", "night", "sweet", "lemon", "mango", "peach", "grape", "world", "ocean", "music", "dance", "movie", "story", "magic", "ghost", "blood", "steel", "glass", "happy", "angry", "brave", "quiet", "noisy", "dress", "shirt", "pants", "shoes", "crown", "sword", "paint", "brush", "clock", "watch", "horse", "zebra", "tiger", "eagle", "shark", "whale", "camel", "sheep", "snake", "apple", "berry", "honey", "bread", "toast", "pizza", "curry", "sauce", "sugar", "spice", "chair", "couch", "floor", "stair", "table", "frame", "shelf", "light", "spark", "shine", "stone", "brick", "metal", "paper", "inked", "words", "write", "story", "novel", "think"
    };
    int word_count = sizeof(words) / sizeof(words[0]);

    // 2️⃣ 정답 무작위 선택
    srand((unsigned int)time(NULL));
    const char *answer = words[rand() % word_count];

    char guess[WORD_LEN + 2];  // +2는 '\n'과 '\0'을 고려
    int attempt;

    printf("=== Wordle ===\n");
    printf("5글자 영어 단어를 맞춰보세요! (총 6번의 기회)\n\n");
    printf("Y는 포함된 알파벳, G는 위치까지 맞는 알파벳\n");

    for (attempt = 1; attempt <= MAX_TRIES; attempt++) {
        printf("%d번째 시도: ", attempt);
        fgets(guess, sizeof(guess), stdin);

        // 개행문자 제거
        guess[strcspn(guess, "\n")] = '\0';

        if (strlen(guess) != WORD_LEN) {
            printf("5글자 단어를 입력해야 합니다.\n\n");
            attempt--;
            continue;
        }

        // 피드백 표시용 버퍼
        char feedback[WORD_LEN + 1];
        for (int i = 0; i < WORD_LEN; i++) {
            if (guess[i] == answer[i])
                feedback[i] = 'G';  // Green (정확히 맞음)
            else if (strchr(answer, guess[i]) != NULL)
                feedback[i] = 'Y';  // Yellow (글자는 있음, 위치는 다름)
            else
                feedback[i] = '.';  // Gray (없음)
        }
        feedback[WORD_LEN] = '\0';

        printf("결과: %s\n", feedback);

        if (strcmp(guess, answer) == 0) {
            printf("정답입니다! '%s'\n", answer);
            return 0;
        }

        printf("\n");
    }

    printf("실패! 정답은 '%s'였습니다.\n", answer);
    return 0;
}
