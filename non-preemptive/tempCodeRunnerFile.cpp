
                            }
                            else
                            {
                                check=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(check)break;
        }
        total_time+=j;
        if(j==p[k].remaining_time)
        {
        p[k].status=finished;
        p[k].turnaround_time = total_time - p[k].arrival_time;
        avg_turnaround_time += p[k].turnaround_time;
        p[k].waiting_time= p[k].turnaround_time-p[k].burst_time;
        avg_waiting_time += p[k].waiting_time;
        }