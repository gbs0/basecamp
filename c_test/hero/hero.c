/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:29:28 by gschiavo          #+#    #+#             */
/*   Updated: 2022/03/31 10:34:35 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Simple C function to calculate Player damage based on Enemy's defense.
// The player should win if the number of the bullets are at least twice the number of enemies.

#include <stdbool.h>
#include <stdint.h>

bool hero(uint32_t bullets, uint32_t dragons) {
  uint32_t dragons_hp = dragons * 2;
  if (dragons_hp > bullets) {
    return false;
  }
  
  return true;
  
}