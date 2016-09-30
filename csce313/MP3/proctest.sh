#!/bin/bash

#******Identifiers******
awk '/^Pid:/ {print "PID = " $2}' /proc/$1/status
awk '/^PPid:/ {print "PPID = " $2}' /proc/$1/status
awk '/^Uid:/ {print "EUID = " $3}' /proc/$1/status
awk '/^Gid:/ {print "EGID = " $3}' /proc/$1/status
awk '/^Uid:/ {print "RUID = " $2}' /proc/$1/status
awk '/^Gid:/ {print "RGID = " $2}' /proc/$1/status
awk '/^Uid:/ {print "FSUID = " $5}' /proc/$1/status
awk '/^Gid:/ {print "FSGID = " $5}' /proc/$1/status

#******State******
awk '/^State:/ {print "State = " $2}' /proc/$1/status

#******Thread Information******
awk '/^NSpid:/ {print "Thread ID = " $2}' /proc/$1/status
awk '/^Threads:/ {print "Number of Threads = " $2}' /proc/$1/status

#******Priority******
awk '{print "Priority Number = " $18}' /proc/$1/stat
awk '{print "Niceness Number = " $19}' /proc/$1/stat

#******Time Information******
awk '{print "stime = " $15}' /proc/$1/stat
awk '{print "utime = " $14}' /proc/$1/stat
awk '{print "cstime = " $17}' /proc/$1/stat
awk '{print "cutime = " $16}' /proc/$1/stat

#******Address Space******
awk '{print "Startcode = " $26}' /proc/$1/stat
awk '{print "Endcode = " $27}' /proc/$1/stat
awk '{print "ESP = " $29}' /proc/$1/stat
awk '{print "EIP = " $30}' /proc/$1/stat

#******Resources******
awk '/^FDSize:/ {print "File Handles = " $2}' /proc/$1/status
awk '/^voluntary_ctxt_switches:/ {print "Voluntary Context Switches = " $2}' /proc/$1/status
awk '/^nonvoluntary_ctxt_switches:/ {print "Involuntary Context Switches = " $2}' /proc/$1/status

#******Processors******
awk '/^Cpus_allowed:/ {print "CPUs Allowed = " $2}' /proc/$1/status
awk '{print "Last Processor Used = " $39}' /proc/$1/stat

#******Memory Map******
echo "Memory Map:"
awk '{print}' /proc/$1/maps