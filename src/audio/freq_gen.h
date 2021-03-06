/*
    Copyright (C) 2005-2009  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// Frequency generator
//
// This file contains definitions of the frequency generator.
// The frequency generator generates tones build from a list of
// frequencies.

#ifndef _FREQ_GEN_H
#define _FREQ_GEN_H

#include <vector>
#include <commoncpp/config.h>

#include "rtp_telephone_event.h"

using namespace std;

class t_freq_gen {
private:
	vector<uint16>	_frequencies;
	int16		_amplitude;
	
public:
	t_freq_gen(vector<uint16> frequencies, int8 db_level);
	t_freq_gen(t_dtmf_ev dtmf, int8 db_level);
	
	// Get sound sample on a particular timestamp in us.
	int16 get_sample(uint32 ts_usec) const;
	void get_samples(int16 *sample_buf, uint16 buf_len, 
			uint32 ts_start, double interval) const;
};

#endif
