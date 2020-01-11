from django.test import TestCase
from django.utils import timezone
from django.urls import reverse
from .models import Question


def create_question(question_text, days):
    """
    Create a question with with a offset of days from now
    """
    now = timezone.now()
    question_time = now + timezone.timedelta(days=days)
    question = Question.objects.create(
        question_text=question_text,
        pub_date=question_time
    )
    return question


class QuestionIndexViewTests(TestCase):
    """
    Test for question index view
    """

    def test_no_questions(self):
        """
        Check if the case without question pass
        """
        response = self.client.get(reverse('polls:index'))
        self.assertEqual(response.status_code, 200)
        self.assertContains(
            response,
            "No polls are available"
        )
        self.assertQuerysetEqual(
            response.context['latest_question_list'],
            []
        )

    def test_past_question(self):
        """
        Questions with a pub_date in the past are displayed on the
        index page.
        """
        create_question(question_text="Past question.", days=-30)
        response = self.client.get(reverse('polls:index'))
        self.assertQuerysetEqual(
            response.context['latest_question_list'],
            ['<Question: Past question.>']
        )

    def test_future_question(self):
        """
        Questions with a pub_date in the future aren't displayed on
        the index page.
        """
        create_question(question_text="Future question.", days=30)
        response = self.client.get(reverse('polls:index'))
        self.assertContains(
            response,
            "No polls are available."
        )
        self.assertQuerysetEqual(response.context['latest_question_list'], [])

    def test_future_question_and_past_question(self):
        """
        Even if both past and future questions exist, only past questions
        are displayed.
        """
        create_question(question_text="Past question.", days=-30)
        create_question(question_text="Future question.", days=30)
        response = self.client.get(reverse('polls:index'))
        self.assertQuerysetEqual(
            response.context['latest_question_list'],
            ['<Question: Past question.>']
        )

    def test_two_past_questions(self):
        """
        The questions index page may display multiple questions.
        """
        create_question(question_text="Past question 1.", days=-30)
        create_question(question_text="Past question 2.", days=-5)
        response = self.client.get(reverse('polls:index'))
        self.assertQuerysetEqual(
            response.context['latest_question_list'],
            ['<Question: Past question 2.>', '<Question: Past question 1.>']
        )


class QuestionModelTests(TestCase):
    """
    Test case to check question model
    """

    def test_was_pubblished_recently_with_future_question(self):
        """
        was_pubblished_recently() returns False for
        questions whose pub_date is in the future.
        """
        future_time = timezone.now() + timezone.timedelta(days=1)
        future_question = Question(pub_date=future_time)
        self.assertIs(future_question.was_published_recently(), False)

    def test_was_pubblished_recently_with_past_question(self):
        """
        was_pubblished_recently() needs to return False
        """
        now = timezone.now()
        past_time = now - timezone.timedelta(days=1, minutes=1)
        past_question = Question(pub_date=past_time)
        self.assertIs(past_question.was_published_recently(), False)

    def test_was_pubblished_recently_with_recent_question(self):
        """
        was_pubblished_recently() needs to return True
        """
        now = timezone.now()
        recent_time = now - timezone.timedelta(hours=23, minutes=59)
        recent_question = Question(pub_date=recent_time)
        self.assertIs(recent_question.was_published_recently(), True)


class QuestionDetailViewTests(TestCase):
    """
    Detail view test cases
    """

    def test_future_question(self):
        """
        The detaild view of a future question needs to return a 404
        """
        question = create_question(question_text='Future question', days=5)
        url = reverse(
            'polls:detail',
            args=(question.id,)    
        )
        response = self.client.get(url)
        self.assertEqual(response.status_code, 404)

    def test_past_question(self):
        """
        The detail view of a question with a pub_date in the past
        displays the question's text.
        """
        past_question = create_question(
            question_text='Past Question.',
            days=-5
        )
        url = reverse(
            'polls:detail',
            args=(past_question.id,)
        )
        response = self.client.get(url)
        self.assertContains(response, past_question.question_text)
