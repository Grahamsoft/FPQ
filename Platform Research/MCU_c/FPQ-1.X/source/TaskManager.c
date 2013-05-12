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
    static int Operation = 1;
    
    switch( Operation )
    {
        case 1:
            InitKeys();
            Operation = 2;
            break;
        
        case 2:
            DataCommsTask();
            InputTask();
            OutputTask();
            break;
    }
}

