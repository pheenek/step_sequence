/**
 * @file 		step_register.h 
 * 
 * @author 		Stephen Kairu (stephenkairu@e-kraal.com) 
 * 
 * @brief	 	This header file contains definitions for a step-register type
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

#ifndef STEP_REGISTER_H_
#define STEP_REGISTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

/**
 * This structure defines a step sequence type
 */
typedef struct {
	uint16_t numSteps;
	uint16_t currentStep;
	bool complete;
} StepSequence_t;

/**
 * @brief	 This function allocates memory for a StepSequence_t type
 * 
 * @return StepSequence_t* 
 */
StepSequence_t *seq_create(void);

/**
 * @brief	 This function frees memory for the StepSequence_t specified (destructor)
 * 
 * @param thisSeq 
 * 
 * @return none
 */
void seq_destroy(StepSequence_t *thisSeq);

/**
 * @brief	 This function initializes the StepSequence_t instance
 * 			with its number of steps
 * 
 * @param thisSeq 
 * @param numSteps 
 */
void seq_init(StepSequence_t *thisSeq, uint16_t numSteps);

/**
 * @brief	 This function returns the current step for a StepSequence_t type
 * 
 * @param thisSeq 
 * @return uint16_t 
 */
uint16_t seq_currentStepGet(StepSequence_t *thisSeq);

/**
 * @brief	 This function moves the StepSequence_t type by a single step
 * 
 * @param thisSeq 
 */
void seq_nextStep(StepSequence_t *thisSeq);

/**
 * @brief	 This function resets the current step for a StepSequence_t type
 * 			The current step is set to the default.
 * 
 * @param thisSeq 
 */
void seq_resetStep(StepSequence_t *thisSeq);

/**
 * @brief	 This function returns whether or not the step-wise sequence has run to its end
 * 
 * @param thisSeq 
 * @return true 
 * @return false 
 */
bool seq_isComplete(StepSequence_t *thisSeq);

#ifdef __cplusplus
}
#endif

#endif
