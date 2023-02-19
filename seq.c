/**
 * @file 		step_register.c 
 * 
 * @author 		Stephen Kairu (stephenkairu@e-kraal.com) 
 * 
 * @brief	 	This source file contains implementations for a step-register type
 * 				The type is used to track sequences that occur in step-wise form, asynchronously
 * 
 * @version 	0.1 
 * 
 * @date 		2023-01-29
 * 
 * ***************************************************************************
 * @copyright Copyright (c) 2023
 * ***************************************************************************
 * 
 */

#include "seq.h"
#include <stddef.h>
#include <stdlib.h>


/**
 * @brief	 This function allocates memory for a StepSequence_t type
 * 
 * @return StepSequence_t* 
 */
StepSequence_t *seq_create(void)
{
	StepSequence_t *seq = malloc(sizeof(StepSequence_t));

	if (seq) return seq;
	else return NULL;
}

/**
 * @brief	 This function frees memory for the StepSequence_t specified (destructor)
 * 
 * @param thisSeq 
 * 
 * @return none
 */
void seq_destroy(StepSequence_t *thisSeq)
{
	free(thisSeq);
}

/**
 * @brief	 This function initializes the StepSequence_t instance
 * 			with its number of steps
 * 
 * @param thisSeq 
 * @param numSteps 
 */
void seq_init(StepSequence_t *thisSeq, uint16_t numSteps)
{
	thisSeq->currentStep = 0;
	thisSeq->numSteps = numSteps;
	thisSeq->complete = false;
}

/**
 * @brief	 This function returns the current step for a StepSequence_t type
 * 
 * @param thisSeq
 * @return uint16_t 
 */
uint16_t seq_currentStepGet(StepSequence_t *thisSeq)
{
	return thisSeq->currentStep;
}

/**
 * @brief	 This function moves the StepSequence_t type forward by a single step
 * 
 * @param thisSeq 
 */
void seq_nextStep(StepSequence_t *thisSeq)
{
	uint16_t nextStep = ((thisSeq->currentStep + 1) % thisSeq->numSteps);
	uint16_t carry = ((thisSeq->currentStep + 1) / thisSeq->numSteps);

	thisSeq->currentStep = nextStep;
	thisSeq->complete = (carry == 1) ? true : false;
}

/**
 * @brief	 This function resets the current step for a StepSequence_t type
 * 			The current step is set to the default.
 * 
 * @param thisSeq 
 */
void seq_resetStep(StepSequence_t *thisSeq)
{
	thisSeq->currentStep = 0;
	thisSeq->complete = false;
}

/**
 * @brief	 This function returns whether or not the step-wise sequence has run to its end
 * 
 * @param thisSeq 
 * @return true 
 * @return false 
 */
bool seq_isComplete(StepSequence_t *thisSeq)
{
	return thisSeq->complete;
}

