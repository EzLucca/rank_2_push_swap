
main
|
|->	input_validation |
|					 |-> ft_split |
|								  |-> ft_putstr_fd
|					              |-> free_arrays
|					              |-> exit
|->  parse_av |
|			  |-> check_repetition |
|			  |					   |-> ft_strncmp |
|			  |									  |-> ft_putstr_fd
|			  |									  |-> exit
|			  |-> check_int |
|							|-> ft_isdigit_mod |
|											   |-> ft_putstr_fd
|											   |-> exit
|->  push_swap	|
|				|-> long_check |
|               |              |-> ft_strcmp |
|               |              |             |-> free 
|               |              |             |-> ft_putstr_fd
|               |              |             |-> exit
|               |              |-> ft_atoi
|               |              |-> ft_itoa
|               |              |-> free
|				|-> add_node
|				|-> ft_atoi 
|				|-> gimme_length
|				|-> gimme_index
|				|-> instructions
|
|->  free_stack |
|				|-> free
|
|->  end of program
