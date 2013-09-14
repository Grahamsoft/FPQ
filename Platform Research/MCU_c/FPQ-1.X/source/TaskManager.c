/* 
 * File:   TaskManager.c
 * Author: David Graham
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "headers/TaskManager.h"
#include "headers/DataCommsTask.h"
#include "headers/InputTask.h"
#include "headers/OutputTask.h"
#include "headers/Model.h"

void TaskManager()
{
    static uint8_t Operation = 1;
    
    switch( Operation )
    {
        case 1:
            InitTime();
            InitKeys();
            InitDataComms();
            Operation = 2;
            break;
        
        case 2:
            Increment_Timer();
            DataCommsTask();
            InputTask();
            Increment_Timer();
            OutputTask();
            break;
    }
}

