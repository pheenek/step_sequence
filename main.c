
#include <stdio.h>
#include "seq.h"

#define NUM_STEPS 5

StepSequence_t *testSeq;

int main(int argc, char const *argv[])
{
    testSeq = seq_create();
    seq_init(testSeq, NUM_STEPS);

    while (!seq_isComplete(testSeq))
    {
        printf("Step: %u\n", seq_currentStepGet(testSeq));

        seq_nextStep(testSeq);
    }

    return 0;

}