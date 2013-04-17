/* 
 * File:   TaskManager.c
 * Author: David Graham
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "TaskManager.h"
#include "DataCommsTask.h"
#include "InputTask.h"
#include "OutputTask.h"
#include "Model.h"

static int Operation = 0;

int TaskManager()
{
    switch( Operation )
    {
        case 0:
            InitKeys();          
            Operation = 1;
            break;
        
        case 1:
            DataCommsTask();
            InputTask();
            OutputTask();
            break;
    }

    return ( EXIT_SUCCESS );
}

