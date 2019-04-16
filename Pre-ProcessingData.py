import re
import string

input_str = "The 5 biggest countries by population in 2017 are China, India, United States, Indonesia, and Brazil."
lower_input_str = input_str.lower()
print(lower_input_str)

input_str = "Box A contains 3 red and 5 white balls, while Box B contains 4 red and 2 blue balls."
result = re.sub(r'\d +', '', input_str)
print(result)

test_string = "This! is a test,, with multiple things() going on with i_t?"

final = test_string.translate(str.maketrans('', '', string.punctuation))
print(final)


text = "The survey was interested in the particulars of respondents’ anger. In its 14 pages, it sought an almost voyeuristic level of detail. It asked the woman to describe the stages of her fury, which words she had shouted, whether punches had been thrown. “In becoming angry, did you wish to get back at, or gain revenge?” the survey inquired. Afterward, did you feel “triumphant, confident and dominant” or “ashamed, embarrassed and guilty”? There were also questions for people like her husband, who had been on the receiving end: “Did the other person’s anger come as a surprise to you, or did you expect that it would occur?” \
\
Greenfield, population 18, 000, was an unusual place to plumb these depths. It was a middle-class town with a prosperous tool-and-die factory, where churches outnumbered bars two to one. Citizens were private and humble, and—except for a few recent letters to the editor lamenting that the high-school hockey team had been robbed in the playoffs—the town showed little evidence of widespread resentment. In fact, this very placidity was why Greenfield had been chosen for the study. \
\
The author of the questionnaire was James Averill, a psychology professor at the University of Massachusetts at Amherst. Averill was a gentle soul, the kind of man who had once returned to a grocery store to apologize to a cashier after becoming annoyed over miscounted change. But he was convinced that his academic colleagues misunderstood anger. He had attended many conferences where researchers had described it as a base instinct, a vestige from our savage past that served no useful purpose in contemporary life. “Everyone basically thought anger was something that mature people and societies ought to suppress, ” Averill told me. “There was this attitude that if you were an angry person, you ought to be a bit embarrassed.” In journal articles and at symposia, academics described anger as a problem to be solved, an instinct with little social benefit. “But that didn’t really make any sense to me, ” he said. \
\
Despite his genial disposition, Averill had been known to mutter angrily when a driver cut him off. He felt bursts of indignation on a regular basis, as did everyone else he knew. And though he rarely acted on these impulses, he suspected that anger wouldn’t be lurking in his psyche unless it served some important purpose. “When something’s bad for us, we usually get rid of it through evolution or social codes. But anger has been a part of humanity for as long as we’ve been alive, ” he said. “It’s in the Bible and novels and plays. It’s one of the most common emotions people say they feel.” \
\
Averill decided that the best way to understand anger was to survey ordinary people—people who get upset at their co-workers, who yell during rush hour—about their experiences. He went looking for an average town and found Greenfield. He figured if he could show that its citizens, despite their contentedness, still experienced occasional bouts of fury, it would be a wake-up call to other researchers that more scrutiny of anger was due."

text_low = text.lower()

text_low_no_numbers = re.sub(r'\d +', '', text_low)

final = text_low_no_numbers.translate(str.maketrans('', '', string.punctuation))

print(final)
