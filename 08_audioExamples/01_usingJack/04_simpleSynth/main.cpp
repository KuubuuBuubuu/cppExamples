#include <iostream>
#include <thread>
#include "jack_module.h"
#include "simpleSynth.h"

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);

  // create a simpleSynth instance
  SimpleSynth simpleSynth((float)jack.getSamplerate(), 60);

  // assign a function to the JackModule::onProces
  jack.onProcess = [&simpleSynth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
  {
    //loop through frames, retrieve sample of sine per frame
    for(unsigned int i = 0; i < nframes; i++) {
      //TODO check type of jack_default_audio_sample_t, double? or float?
      outBuf[i] = simpleSynth.getSample();
      simpleSynth.tick();
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  std::cout << "\n\nPress 'a', 's','d', 'f','g','h','j','k' to"
    <<"alter the pitch (C major scale).\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
      //a -> 60 - c
      case 'a':
        simpleSynth.setMidiPitch(60);
        break;
      //s -> 62 - d
      case 's':
        simpleSynth.setMidiPitch(62);
        break;
      //d -> 64 - e
      case 'd':
        simpleSynth.setMidiPitch(64);
        break;
      //f -> 65 - f
      case 'f':
        simpleSynth.setMidiPitch(65);
        break;
      //g -> 67 - g
      case 'g':
        simpleSynth.setMidiPitch(67);
        break;
      //h -> 69 - a
      case 'h':
        simpleSynth.setMidiPitch(69);
        break;
      //j -> 71 - b
      case 'j':
        simpleSynth.setMidiPitch(71);
        break;
      //k -> 72 - c
      case 'k':
        simpleSynth.setMidiPitch(72);
        break;
    }
  }

  //end the program
  return 0;
} // main()
