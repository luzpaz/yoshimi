/*
    LFOParams.h - Parameters for LFO

    Original ZynAddSubFX author Nasca Octavian Paul
    Copyright (C) 2002-2005 Nasca Octavian Paul
    Copyright 2009-2011, Alan Calvert
    Copyright 2017-2019, Will Godfrey
    Copyright 2020 Kristian Amlie

    This file is part of yoshimi, which is free software: you can redistribute
    it and/or modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    yoshimi is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.   See the GNU General Public License (version 2 or
    later) for more details.

    You should have received a copy of the GNU General Public License along with
    yoshimi; if not, write to the Free Software Foundation, Inc., 51 Franklin
    Street, Fifth Floor, Boston, MA  02110-1301, USA.

    This file is derivative of original ZynAddSubFX code.

*/

#ifndef LFO_PARAMS_H
#define LFO_PARAMS_H

#include <sys/types.h>

#include "Misc/XMLwrapper.h"
#include "Params/Presets.h"

class SynthEngine;

class LFOParams : public Presets
{
    public:
        LFOParams(float Pfreq_, float Pintensity_, float Pstartphase_,
                  unsigned char PLFOtype_, float Prandomness_,
                  float Pdelay_, unsigned char Pcontinous, int fel_, SynthEngine *_synth);
        ~LFOParams() { }

        void add2XML(XMLwrapper *xml);
        void defaults(void);
        void setPfreq(int32_t n);
        void getfromXML(XMLwrapper *xml);
        void setPintensity(float n) { Pintensity = n; presetsUpdated(); }
        void setPstartphase(float n) { Pstartphase = n; }
        void setPLFOtype(unsigned char n) { PLFOtype = n; presetsUpdated(); }
        void setPrandomness(float n) { Prandomness = n; presetsUpdated(); }
        void setPfreqrand(float n) { Pfreqrand = n; presetsUpdated(); }
        void setPdelay(float n) { Pdelay = n; }
        void setPbpm(unsigned char n) { Pbpm = n; }
        void setPcontinous(unsigned char n) { Pcontinous = n; presetsUpdated(); }
        void setPstretch(float n) { Pstretch = n; presetsUpdated(); }

        // MIDI Parameters
        int32_t PfreqI;
        float Pfreq;
        float Pintensity;
        float Pstartphase;
        unsigned char PLFOtype;
        float Prandomness;
        float Pfreqrand;
        float Pdelay;
        unsigned char Pbpm;
        unsigned char Pcontinous;
        float Pstretch;

        int fel;         // kind of LFO - 0 frequency, 1 amplitude, 2 filter
       // static int time; // used by Pcontinous - moved to SynthEngine to make it per-instance

    private:
        // Default parameters
        unsigned char Dfreq;
        unsigned char Dintensity;
        unsigned char Dstartphase;
        unsigned char DLFOtype;
        unsigned char Drandomness;
        unsigned char Ddelay;
        unsigned char Dcontinous;
};

class LFOlimit
{
    public:
        float getLFOlimits(CommandBlock *getData);
};

/*
 * This is a new replacement for limits that can be directly
 *  accessed anywhere that includes this header.
 */
struct LFOminmax{
    float min;
    float max;
    float def;
    bool learn;
    bool integer;
};
namespace LFODEF{
    const LFOminmax ampFreq {0,1,0.625,true,false};
    const LFOminmax freqFreq {0,1,0.546875,true,false};
    const LFOminmax filtFreq {0,1,0.625,true,false};
    const LFOminmax voiceAmpFreq {0,1,0.703125,true,false};
    const LFOminmax voiceFreqFreq {0,1,0.390625,true,false};
    const LFOminmax voiceFiltFreq {0,1,0.390625,true,false};

    const LFOminmax depth {0,127,0,true,false};
    const LFOminmax voiceAmpDepth {0,127,32,true,false};
    const LFOminmax voiceFreqDepth {0,127,40,true,false};
    const LFOminmax voiceFiltDepth {0,127,20,true,false};

    const LFOminmax start {0,127,64,true,false};
    const LFOminmax voiceFreqStart {0,127,0,true,false};

    const LFOminmax delay {0,127,0,true,false};
    const LFOminmax voiceAmpDelay {0,127,30,true,false};


    const LFOminmax ampRnd {0,127,0,true,false};
    const LFOminmax freqRnd {0,127,0,true,false};

    const LFOminmax stretch {0,127,64,true,false};

    const LFOminmax type {0,9,0,false,true};
}
namespace LFOSWITCH{
    const bool BPM = false;
    const bool continuous = false;
}
#endif
