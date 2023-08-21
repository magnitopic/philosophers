# Philosophers 💭

In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

<div align="center">
	<img width="650px" alt="Philo" src="https://github.com/magnitopic/philosophers/assets/21156058/f0d09e7e-5d25-44fb-92fa-9e361ab098b8">
</div>

# Program

## Initial installation and compilation

```bash
git clone https://github.com/magnitopic/philosophers.git
cd philosophers/philo
make
```

## Usage

**Note:** Times are measured in milliseconds.

```bash
./philo "number_of_philos" "time_to_die" "time_to_eat" "time_to_sleep" "times_a_philo_must_eat(optional)"
```

### Examples

Normal execution

```bash
./philo 5 800 200 200
```

Every philo will eat 50 times

```bash
./philo 5 800 200 200 50
```
