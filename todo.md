
In this push there are a collection of changes that rewrap stimulus and 
behaviour to belong to a finite state machine.
At the moment I've only bothered to make creatures that have a one-track mind but 
the foundations are there for workable behaviour.

Things that need to be changed are:
 * make a CTargetInfo class to tell behaviours what they are currently targetting
 * make stimulus return a target when it sees something or a nullptr when it doesn't
 * targetinfo can contain no info to indicate that the stimulus is non-targeting
 * once this exists behaviours should be independant of the axes
 * instead they will deal with coordinates relative to the target direction

Then this targetting system will probably be enough to start working on actual mutation
 * make CStimulus more robust
 * make CMutator objects that contain an RNG
 * make CMutator methods:
    * link/branch X to state Y from stimulus Z (Y and Z may themselves be new)
    * change abort time of state X by +-n seconds
    * destroy random link from state X and collect garbage (delete any dangling states)
    * mutate properties of behaviour
    * adapt a behaviour into a more specialized behaviour
    * mutate properties of a stimulus
    * adapt a stimulus into a version with more specialized input or output
 * make mitosis or budding behaviour (no need to balance yet)
 * perhaps make this using an "exitBehaviour(self, world)" method that is activated when a state is aborted

I have no doubt there are plenty of things to consider but these are the things most relevant to the
changes being made in this commit
