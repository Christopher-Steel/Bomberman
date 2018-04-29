#ifndef GDL_GAMECLOCK_HPP
# define GDL_GAMECLOCK_HPP

# include <list>
# include "IClock.hpp"
# include "Clock.hpp"

namespace gdl
{
	class Game;

	////////////////////////////////////////////////////////////
	/// Forward declaration of GameClockImpl.
	////////////////////////////////////////////////////////////
	class GameClockImpl;

	////////////////////////////////////////////////////////////
	/// GameClock provides a main clock for the entire game.
	////////////////////////////////////////////////////////////
	class	GameClock : public IClock
	{
	private:
		////////////////////////////////////////////////////////////
		/// Default constructror.
		////////////////////////////////////////////////////////////
		GameClock();

		////////////////////////////////////////////////////////////
		/// Default destructror.
		////////////////////////////////////////////////////////////
		~GameClock();

	public:
		////////////////////////////////////////////////////////////
		/// Start the clock.
		////////////////////////////////////////////////////////////
		void	play(void);

		////////////////////////////////////////////////////////////
		/// Stop the clock until you play it again.
		////////////////////////////////////////////////////////////
		void	pause(void);

		////////////////////////////////////////////////////////////
		/// Up the time of the clock.
		////////////////////////////////////////////////////////////
		void	update(void);

		////////////////////////////////////////////////////////////
		/// Reset the clock to 0.
		////////////////////////////////////////////////////////////
		void	reset(void);

		////////////////////////////////////////////////////////////
		/// Return the time since the last Update call.
		///
		/// \return The time in float.
		////////////////////////////////////////////////////////////
		float	getElapsedTime(void) const;

		////////////////////////////////////////////////////////////
		/// Return the time between now and the start of the Game.
		///
		/// \return The time in float.
		////////////////////////////////////////////////////////////
		float	getTotalGameTime(void) const;

		////////////////////////////////////////////////////////////
		/// Add new clock to Update
		////////////////////////////////////////////////////////////
		void	addNewClock(gdl::Clock *newClock);

	private:
		////////////////////////////////////////////////////////////
		/// GameClock implementation.
		////////////////////////////////////////////////////////////
		GameClockImpl&		clock_;
		////////////////////////////////////////////////////////////
		/// Indicate if this clock is active.
		////////////////////////////////////////////////////////////
		bool			isActiv_;
		////////////////////////////////////////////////////////////
		/// Elapsed time since the last update.
		////////////////////////////////////////////////////////////
		float			elapsedTime_;
		////////////////////////////////////////////////////////////
		/// Elapsed time since the game is launched.
		////////////////////////////////////////////////////////////
		float			totalGameTime_;

		friend class Game;
	};
}

#endif /* !GDL_GAMECLOCK_HPP */
