/*
** my.h for  in /home/arnhol_m/rendu/synth/agenda
** 
** Made by martin Arnholz
** 
** Started on  Mon Jun 29 14:28:36 2015 martin Arnholz
** Last update Mon Apr 25 14:19:00 2016 
*/

#ifndef MY_H_
#define MY_H_

typedef struct s_employee
{
  char		*name;
  char		*forename;
  char		*id_name;
  char		*poste;
  char		*code_post;
  struct	s_employee *next;
  struct	s_employee *previous;
  struct	s_employee *first;
  struct	s_employee *last;
}	t_employee;

typedef struct s_meeting
{
  char		*place;
  char		*date;
  char		*id;
  char		**id_employee;
  struct	s_meeting *next;
  struct	s_meeting *previous;
  struct	s_meeting *first;
  struct	s_meeting *last;
}	t_meeting;

t_employee  *init_employee();
t_meeting   *init_meeting();
char	*my_strdup(char *str);
int	my_strlen(char *str);
char    *get_next_line(const int fd);
char	*att_bal(char *str);
int	check_double(t_employee *employee ,char *str);
int	is_alpha(char c);
char	*get_att(char *str);
char	*c_create(char *str);
char	*get_next_line(const int fd);
int     count_word(char *str ,char sep);
int     size_tab(char **tab);
int     count_char(char *str, int i, char sep);
char    **my_str_to_wordtab(char *str ,char sep);
int	pars_it(char *str ,t_employee *employee, t_meeting *meeting);
int	add_name(t_employee **employee, char **toc);
int	add_meet(t_meeting **meeting, char **toc);
void    del_node(t_employee *employee, char **toc);
void	print_employee(t_employee *employee);
void	print_meeting(t_meeting *meeting);
void    inv_meet(t_meeting *meeting, char **toc);
void    ex_mee(t_meeting *meeting, char **toc);

#endif
