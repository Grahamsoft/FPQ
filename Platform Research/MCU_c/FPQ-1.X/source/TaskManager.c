/* 
 * File:   TaskManager.c
 * Author: David Graham
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "TaskManager.h"
#include "DataCommsTask.h"
#include "TimerTask.h"

int TaskManager()
{
    DataCommsTask();
    TimerTask();
    return ( EXIT_SUCCESS );
}

