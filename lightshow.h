
typedef struct Execution {
    int bits[15];
    int numberOfExecutions;
};

int TOTAL_STEPS=278;
Execution LIGHT_SHOW[278] = { 
{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},2},
{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},1},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},1},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},2},
{{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},2},
{{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},1},
{{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},1},
{{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},1},
{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},1},
{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},1},
{{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},2},
{{1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},1},
{{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},1},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},1},
{{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},1},
{{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},1},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},1},
{{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},1},
{{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},1},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},1},
{{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},2},
{{1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},1},
{{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},1},
{{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},1},
{{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},1},
{{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},2},
{{0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},2},
{{0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},2},
{{0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},1},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},1},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},2},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},2},
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},3},
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},3}};