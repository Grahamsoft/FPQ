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

void TaskManager()
{
    static int Operation = 0;
    
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
}

